# $NetBSD$

PKGNAME=	unit-${LANG}-${UNIT_VERSION}
COMMENT=	Ruby module for NGINX Unit

LANG=		ruby
MODNAME=	${LANG}

MAINTAINER=	osa@FreeBSD.org

USE_LANGUAGES+=	c

post-configure:
	cd ${WRKSRC} && \
	./configure ${LANG} --module=${MODNAME}

.include "../../lang/${LANG}/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
