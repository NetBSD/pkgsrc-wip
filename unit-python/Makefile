# $NetBSD$

PKGNAME=	unit-${LANG}-${UNIT_VERSION}
COMMENT=	Python module for NGINX Unit

LANG=		python
MODNAME=	${LANG}

MAINTAINER=	osa@FreeBSD.org

USE_LANGUAGES+=	c

post-configure:
	cd ${WRKSRC} && \
	./configure ${LANG} --module=${MODNAME} \
		--config=${LANG}${PYVERSSUFFIX}-config

.include "../../lang/${LANG}/application.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
