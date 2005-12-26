# $NetBSD: package.mk,v 1.1 2005/12/26 10:17:38 ykomatsu Exp $
#

DEPENDS+=		zope3-unstable>=3.2.0b2:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
