# $NetBSD$

DISTNAME=	b2g4pipe235
PKGNAME=	blast2go-2.3.5
CATEGORIES=	biology
MASTER_SITES=	https://www.blast2go.org/_media/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.blast2go.org/
COMMENT=	GO annotation and functional genome analysis
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/b2g4pipe
USE_JAVA=	run
USE_TOOLS+=	pax
NO_BUILD=	yes

SUBST_CLASSES+=		java
SUBST_STAGE.java=	pre-configure
SUBST_FILES.java=	blast2go.sh
SUBST_VARS.java=	PREFIX JAVA_BINPREFIX

INSTALLATION_DIRS+=	bin libexec/blast2go share/doc/blast2go share/examples/blast2go

post-extract:
	${CP} ${FILESDIR}/blast2go.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blast2go.sh ${DESTDIR}${PREFIX}/bin/blast2go
	cd ${WRKSRC} && ${PAX} -rw blast2go.jar ext ${DESTDIR}${PREFIX}/libexec/blast2go
	${INSTALL_DATA} ${WRKSRC}/b2gpipe_readme_v2_3_5.txt ${DESTDIR}${PREFIX}/share/doc/blast2go
	${INSTALL_DATA} ${WRKSRC}/b2gPipe.properties ${DESTDIR}${PREFIX}/share/examples/blast2go

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
