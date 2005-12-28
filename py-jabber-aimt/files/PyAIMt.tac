# Path to the PyMSNt installed directory
PATH = "@PREFIX@/@TRANSPORTDIR@"

# Path to the configuration file
CONFIG = "@PKG_SYSCONFDIR@/pymsnt.xml"

# User privileges to switch to if run as root
USER="@JABBERD_USER@"
GROUP="@JABBERD_GROUP@"

####
# You shouldn't need to modify below this line
####


# Make PATH (@PREFIX@/@TRANSPORTDIR@) is in the PYTHONPATH
import sys
import os
import os.path
sys.path[0] = os.path.abspath(PATH)
os.chdir(PATH)

# gather the translation from the name to the UID/GID
import pwd
pw=pwd.getpwnam(USER)

import grp
gp=grp.getgrnam(GROUP)

# Set up the service
import config
config.configFile = CONFIG
import main
from twisted.application import service
application = service.Application("PyAIMt", uid=pw.pw_uid, gid=gp.gr_gid)
service = main.App()
service.c.setServiceParent(application)

