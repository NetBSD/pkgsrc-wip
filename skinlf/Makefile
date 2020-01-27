# $NetBSD: Makefile,v 1.1 2014/11/01 13:21:35 makoto Exp $
#
DISTNAME=	skinlf-1.2.3-20020729
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/skinlf/files/SkinLF/1.2.3/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/skinlf/
COMMENT=
LICENSE=	skin-look-and-feel-license

AUTO_MKDIRS=	yes
WRKSRC=		${WRKDIR}/${PKGBASE}
NO_BUILD=	yes

INSTALLATION_DIRS= \
	lib/java/skinlf

JAR_FILES= \
	lib/nativeskin.jar \
	lib/skinlf.jar

do-install:
	(cd ${WRKSRC}; \
	for i in ${JAR_FILES} ;do \
	  ${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/lib/java/skinlf/${i}; done ; \
	)

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
