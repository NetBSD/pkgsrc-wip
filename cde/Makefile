# $NetBSD: Makefile,v 1.16 2014/07/29 13:14:55 obache Exp $
#
DISTNAME=	cde-src-2.2.2
PKGNAME=	${DISTNAME:S/-src-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdesktopenv/}

MAINTAINER=	jelle@jellehermsen.nl
HOMEPAGE=	http://cdesktopenv.sourceforge.net/
COMMENT=	Common Desktop Environment
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison bdftopcf mkfontdir ksh awk:run
BUILD_TARGET=	World

MAKE_JOBS_SAFE=	no

DEPENDS+=	ast-ksh-[0-9]*:../../shells/ast-ksh

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

PKG_SYSCONFSUBDIR=	dt

CFLAGS+=		-I${X11BASE}/include/X11

IMAKE_DEFINES+=		-DCplusplusCmd=${CXX}
IMAKE_DEFINES+=		-DLibraryCplusplusCmd=${CXX}
IMAKE_DEFINES+=		-DX11ProjectRoot=${X11BASE}
IMAKE_DEFINES+=		-DProjectRoot=${PREFIX}
IMAKE_DEFINES+=		-DTopMotifInclude=${MOTIFBASE}/include
IMAKE_DEFINES+=		-DCDEProjectRoot=${PREFIX}/dt
IMAKE_DEFINES+=		-DCdeInstallationTop=${PREFIX}/dt
IMAKE_DEFINES+=		-DCdeConfigurationTop=${PKG_SYSCONFDIR}
IMAKE_DEFINES+=		-DCdeLogfileTop=${VARBASE}/dt
#IMAKE_DEFINES+=	-DTclLibrary=${BUILDLINK_PREFIX.tcl}/lib
IMAKE_DEFINES+=		-DUseInstalledX11=YES
#IMAKE_DEFINES+=	-DKornShell=${TOOLS_PATH.ksh}
IMAKE_DEFINES+=		-DDtKornShell=${PREFIX}/dt/bin/dtksh
BUILD_MAKE_FLAGS+=	BOOTSTRAPCFLAGS=${CFLAGS:Q}
BUILD_MAKE_FLAGS+=	IMAKE_DEFINES=${IMAKE_DEFINES:Q}
#MAKE_ENV+=		MFLAGS=KORNSHELL=${TOOLS_PATH.ksh}

BUILD_DEFS+=		VARBASE
OWN_DIRS+=		${VARBASE}/dt
OWN_DIRS+=		${VARBASE}/dt/tmp
OWN_DIRS+=		${VARBASE}/dt/appconfig/appmanager
.for i in appmanager help icons types
.  for j in C de_DE.ISO8859-1 es_ES.ISO8859-1 fr_FR.ISO8859-1 it_IT.ISO8859-1
OWN_DIRS+=		${PKG_SYSCONFDIR}/appconfig/${i}/${j}
.  endfor
.endfor
OWN_DIRS+=		${PKG_SYSCONFDIR}/config
OWN_DIRS+=		${PKG_SYSCONFDIR}/config/Xsession.d
BUILDLINK_PASSTHRU_DIRS+= ${PREFIX}/dt/lib

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_FILES.destdir=	admin/IntegTools/dbTools/installCDE.src
SUBST_SED.destdir=	-e 's,-D / ,-D $$DESTDIR ,'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	databases/*.udb databases/*.src
SUBST_SED.paths=	-e 's,/usr/dt,${PREFIX}/dt,g'

SUBST_CLASSES+=		dtksh
SUBST_STAGE.dtksh=	pre-configure
SUBST_FILES.dtksh=	programs/dthelp/dthelpgen/dthelpgen.dtsh
SUBST_SED.dtksh=	-e 's,/usr/dt/bin/dtksh,${PREFIX}/dt/bin/dtksh,g'

SUBST_CLASSES+=		awk
SUBST_STAGE.awk=	pre-configure
SUBST_FILES.awk=	programs/dtlogin/config/Xreset.src
SUBST_SED.awk=		-e 's, /bin/awk , ${AWK} ,g'

RCD_SCRIPTS=		dtlogin

do-install:
	${RUN}cd ${WRKSRC}/admin/IntegTools/dbTools; \
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ./installCDE -s ${WRKSRC}

# LinkOtherIcons in confiRun
#post-install:
#.for i fphelp.t.pm help.t.pm paint.l.pm paint.m.pm paint.t.pm penpad.t.pm term.t.pm
#	${LN} -s $i ${DESTDIR}${PREFIX}/dt/appconfig/icons/C/F${i}
#.endfor

# from databases/CDE-RUN.*
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtprintinfo ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtsession ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtterm ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtapppgather ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtmail ${REAL_ROOT_USER} mail 2511
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtmailpr ${REAL_ROOT_USER} mail 2511

.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
#.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
