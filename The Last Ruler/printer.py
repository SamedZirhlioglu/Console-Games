class bcolors:
    CEND        = '\33[0m'
    CSELECTED   = '\33[7m'
    CBLACK      = '\33[30m'
    CRED        = '\33[31m'
    CGREEN      = '\33[32m'
    CYELLOW     = '\33[33m'
    CBLUE       = '\33[34m'
    CVIOLET     = '\33[35m'
    CBEIGE      = '\33[36m'
    CREDBG      = '\33[41m'
    CGREENBG    = '\33[42m'
    CYELLOWBG   = '\33[43m'
    CBLUEBG     = '\33[44m'
    CVIOLETBG   = '\33[45m'
    CBEIGEBG    = '\33[46m'
    CWHITEBG    = '\33[47m'

def printer(text):
    print(bcolors.CSELECTED + text + bcolors.CEND)
    print(bcolors.CBLACK + text + bcolors.CEND)
    print(bcolors.CRED + text + bcolors.CEND)
    print(bcolors.CGREEN + text + bcolors.CEND)
    print(bcolors.CYELLOW + text + bcolors.CEND)
    print(bcolors.CBLUE + text + bcolors.CEND)
    print(bcolors.CVIOLET + text + bcolors.CEND)
    print(bcolors.CBEIGE + text + bcolors.CEND)
    print(bcolors.CREDBG + text + bcolors.CEND)
    print(bcolors.CGREENBG + text + bcolors.CEND)
    print(bcolors.CYELLOWBG + text + bcolors.CEND)
    print(bcolors.CBLUEBG + text + bcolors.CEND)
    print(bcolors.CVIOLETBG + text + bcolors.CEND)
    print(bcolors.CBEIGEBG + text + bcolors.CEND)
    print(bcolors.CWHITEBG + text + bcolors.CEND)
    