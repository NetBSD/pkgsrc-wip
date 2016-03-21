# $NetBSD$

DISTNAME=	jitsi-src-2.8.5426
CATEGORIES=	chat
MASTER_SITES=	https://download.jitsi.org/jitsi/src/
EXTRACT_SUFX=	.zip

MAINTAINER=	coypu@sdf.org
HOMEPAGE=	https://jitsi.org
COMMENT=	
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/jitsi
USE_LANGUAGES=	c c++

do-build:
	$(RUN)$(_ULIMIT_CMD) cd $(WRKSRC) && \
	  $(PKGSRC_SETENV) $(MAKE_ENV) \
	    ant -nouserlib rebuild

do-install:
	cd ${WRKSRC} && ./resources/install/generic/run.sh 

DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
