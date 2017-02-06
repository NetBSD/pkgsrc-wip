# $NetBSD$

DISTNAME=	JabRef-3.8.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jabref/}
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jabref.org/
COMMENT=	Open source bibliography reference manager
LICENSE=	mit

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
PKG_JVMS_ACCEPTED=	openjdk8 oracle-jdk8
INSTALLATION_DIRS=	bin share/java

SUBST_CLASSES+=		script
SUBST_STAGE.script=	pre-install
SUBST_MESSAGE.script=	Generating script file.
SUBST_FILES.script=	jabref
SUBST_SED.script+=	-e "s|@SH@|${SH}|g"
SUBST_SED.script+=	-e "s|@JAVA_BINPREFIX@|${JAVA_BINPREFIX}|g"
SUBST_SED.script+=	-e "s|@JABREF_PREFIX@|${PREFIX}/share/java/|g"
SUBST_SED.script+=	-e "s|@JABREF_JAR@|${DISTNAME}.jar|g"

do-configure:
	${CP} ${FILESDIR}/jabref ${WRKSRC}/jabref

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/share/java
	${INSTALL_SCRIPT} ${WRKSRC}/jabref ${DESTDIR}${PREFIX}/bin/jabref

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
