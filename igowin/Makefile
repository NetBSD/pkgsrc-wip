# $NetBSD: Makefile,v 1.5 2004/08/16 21:14:06 rillig Exp $
#

DISTNAME=		igowin
PKGNAME=		igowin-1.0
CATEGORIES=		games
MASTER_SITES=		http://www.smart-games.com/
EXTRACT_SUFX=		.exe

# Igowin is distributed as a self extracting zip file wrapped by a Win32
# program. The download location is given with the MASTER_SITES variable
# above. The filename is composed from the DISTNAME and the EXTRACT_SUFX.
# The default for EXTRACT_SUFX is .tar.gz, and you only need to define it
# in such special cases like this. As Igowin is a game, I placed it into
# the category "games".

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.smart-games.com/
COMMENT=		Go playing program

# The MAINTAINER is the person who keeps an eye on the pkgsrc package.
# The HOMEPAGE is saved with the binary package. You can see it if you
# run "pkg_info igowin". The comment is a short statement about the pack-
# age.

BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
DEPENDS+=		wine-[0-9]*:../../emulators/wine

# There are two types of dependency a package can have. Igowin needs unzip
# to extract the distribution file, but doesn't need it later to run. On
# the other side it needs wine (the WINdows Emulator) to run, but this is
# not required at build time.

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${EXTRACT_CMD.zip}
NO_BUILDLINK=		yes
NO_TOOLS=		yes
NO_BUILD=		yes

# Normally the working directory for the source files (WRKSRC) is
# ${WRKDIR}/${DISTNAME}, as most distribution archives contain a directory
# with that name where the other files are found. We don't need this
# subdirectory.
#
# Another feature which is very seldom used is the definition of a new
# EXTRACT_CMD. There are a number of predefined EXTRACT_CMDs for .zip,
# .tar.gz, .tar.bz2, and so on. For .exe files there is none. So I just
# set the EXTRACT_CMD to the one that is usually used for .zip files.
#
# We don't need to build the package, we don't need any special tools
# like autoconf and automake, and even the buildlink framework is useless
# for this package. So we disable them.

IGOWIN_FILES=		grain.bmp igowin.exe igowin.hlp readme.txt tutor.hlp
IGOWIN_DIR=		${PREFIX}/libdata/${PKGNAME}

# In the distribution file there are the IGOWIN_FILES. These files will
# be installed in IGOWIN_DIR. How that happens will be explained later.
# In IGOWIN_FILES you can see the preferred way to specify a list of things.
# Just separate them by spaces.

INSTALLATION_DIRS=	bin libdata/${PKGNAME}

# The INSTALLATION_DIRS are created before the package is installed. This
# way I don't have to worry how to create them, they will just be there
# when the installation starts.

do-configure:
.for _F_ in igowin.sh
	@${SED} -e 's|@SHELL@|${SHELL}|g'			\
		-e 's|@TEST@|${TEST}|g'				\
		-e 's|@MKDIR@|${MKDIR}|g'			\
		-e 's|@RM@|${RM}|g'				\
		-e 's|@LN@|${LN}|g'				\
		-e 's|@PKGDIR@|${IGOWIN_DIR}|g'			\
		-e 's|@FILES@|${IGOWIN_FILES}|g'		\
		${FILESDIR}/${_F_}.in > ${WRKSRC}/${_F_}
.endfor

# The file igowin.sh is a wrapper script that I wrote to execute Igowin.
# The special thing about it is that it expects all the data files in
# the current directory. Therefore the script builds that environment
# and executes Igowin therein.
#
# To be somewhat portable a number of programs are not hardcoded in
# the script, but will be replaced in the configure phase. For this to
# happen, I have overwritten the do-configure make target. Although I have
# only one script to configure I have choosen to use a loop.
#
# The loop takes the file from the FILESDIR, runs it through the SED filter
# and then saves the result in the WRKSRC, together with the other files.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igowin.sh ${PREFIX}/bin/igowin
.for _F_ in ${IGOWIN_FILES}
	${INSTALL_DATA} ${WRKSRC}/${_F_} ${IGOWIN_DIR}/${_F_}
.endfor

# Because Igowin does not know how to install in a UNIX filesystem hier-
# archy I have to provide my own installation procedure.
# The fist line installs the wrapper script igowin.sh. The INSTALL_SCRIPT
# command is suited for all kinds of script programs, in contrast to
# compiled programs, which you would install using INSTALL_PROGRAM.
# The INSTALL_SCRIPT and INSTALL_PROGRAM commands make sure the installed
# files are executable.
#
# The rest of the installation procedure installs the data files (which
# should not be executable) using the command INSTALL_DATA.

.include "../../mk/bsd.pkg.mk"
