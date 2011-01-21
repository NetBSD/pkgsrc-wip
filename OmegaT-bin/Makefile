# $NetBSD: Makefile,v 1.6 2011/01/21 12:38:26 ryo-on Exp $
#

DISTNAME=	OmegaT_2.0.5_04_Without_JRE
PKGNAME=	${DISTNAME:S/OmegaT_/OmegaT-bin-/:S/_Without_JRE//:S/_/./}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omegat/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.omegat.org/
COMMENT=	The translation memory (TM) application written in Java

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.
USE_LANGUAGES=	# none

SUBST_CLASSES+=			fix-omegat
SUBST_STAGE.fix-omegat=		pre-configure
SUBST_MESSAGE.fix-omegat=	fixing pathes
SUBST_FILES.fix-omegat=		OmegaT
SUBST_SED.fix-omegat=		-e 's,@OMEGATDIR@,${PREFIX}/${OMEGATDIR}/,g'
SUBST_SED.fix-omegat+=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME}/,g'

OMEGATDIR=	opt/OmegaT

INSTALLATION_DIRS=	bin \
			${OMEGATDIR} \
			${OMEGATDIR}/docs \
			${OMEGATDIR}/images \
			${OMEGATDIR}/lib
pre-patch:
	${INSTALL_DATA} ${FILESDIR}/OmegaT ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/${OMEGATDIR}
	${INSTALL_DATA} ${WRKSRC}/*html ${DESTDIR}${PREFIX}/${OMEGATDIR}
	${INSTALL_DATA} ${WRKSRC}/OmegaT.jar ${DESTDIR}${PREFIX}/${OMEGATDIR}
	cd ${WRKSRC}/docs && pax -rw -pmp * ${DESTDIR}${PREFIX}/${OMEGATDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/images/* ${DESTDIR}${PREFIX}/${OMEGATDIR}/images
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/${OMEGATDIR}/lib
	${INSTALL_DATA} ${FILESDIR}/omegat.prefs ${DESTDIR}${PREFIX}/${OMEGATDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/OmegaT ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
