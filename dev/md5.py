import sys
import re


class ImplementationGenerator:

    def __init__(self, path, fd):
        self.path = path
        self.fd = fd

    @classmethod
    def putFunc(self, split, wfd):
        print split;
        buffs = [];
        for index, symbol in enumerate(split[0]):
            buffs.append("b->" + (split[0][index]).lower());
        a = buffs[0];
        b = buffs[1];
        c = buffs[2];
        d = buffs[3];
        wfd.write("\t" + a + " = " + b + " + rl((" + a + " + md_h" + "(" + b + ", " \
        + c + ", " + d + ") + buff["+ split[1] +"] + g_st[" \
        + str(int(split[3]) - 1) + "]), " + split[2] + ");\n");

    @classmethod
    def generateCode(self):
        filename = path + "_implementer";
        wfd = open(filename, 'w');
        for line in fd:
            split = re.split('\W+', line)
            split = filter(None, split)
            self.putFunc(split, wfd);
        print "created implementation at " + filename

if len(sys.argv) >= 2:
     path = sys.argv[1]
else:
    sys.exit("you shall add the path of your round file")
try:
    fd = open(path, "r")
except:
    sys.exit("could not open %s" % path)

gen = ImplementationGenerator(path, fd);
gen.generateCode();
