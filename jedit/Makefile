# $NetBSD$

PKGBASE=	jedit
VERSION=	5.3.0
PKGNAME=	${PKGBASE}-${VERSION}
DISTNAME=	${PKGBASE}${VERSION}install
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jedit/}
EXTRACT_SUFX=	.jar

MAINTAINER=	jared_pkgsrc@gmail.com
HOMEPAGE=	http://jedit.org/
COMMENT=	Text editor written in Java
LICENSE=	gnu-gpl-v2

NO_BUILD=		yes
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk7 openjdk7 oracle-jdk8 openjdk8

USE_TOOLS+=	unzip tar pax cp

WRKSRC=		${WRKDIR}/${PKGBASE}_staging

SHAREDIR=	${PREFIX}/share/${PKGBASE}

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_SHLIBS_SUPPORTED=	no

SUBST_CLASSES+=		launcher
SUBST_STAGE.launcher=	pre-configure
SUBST_FILES.launcher=	jedit
SUBST_SED.launcher+=	-e 's,@PKG_JAVA_HOME@,'${PKG_JAVA_HOME}',g'
SUBST_SED.launcher+=	-e 's,@JEDIT_HOME@,'${SHAREDIR:Q}',g'

post-extract:
	${RUN} ${MKDIR} ${WRKSRC}
	${RUN} unzip -q -d ${WRKDIR} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}
	${RUN} ${TAR} -C ${WRKSRC} -xjf ${WRKDIR}/installer/jedit-api.tar.bz2
	${RUN} ${TAR} -C ${WRKSRC} -xjf ${WRKDIR}/installer/jedit-macros.tar.bz2
	${RUN} ${TAR} -C ${WRKSRC} -xjf ${WRKDIR}/installer/jedit-program.tar.bz2
	${RUN} ${CP} ${WRKDIR}/jedit.1 ${WRKSRC}
	${RUN} ${CP} ${FILESDIR}/jedit.sh ${WRKSRC}/jedit

do-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${RUN} for f in jars doc jedit.jar keymaps macros modes properties startup; \
	do \
		cd ${WRKSRC} && ${PAX} -rw -pm $${f} ${DESTDIR}${SHAREDIR}; \
	done
	${RUN} ${INSTALL_SCRIPT} ${WRKSRC}/jedit ${DESTDIR}${PREFIX}/bin

post-install:
	${RUN} ${INSTALL_MAN} ${WRKSRC}/jedit.1	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
