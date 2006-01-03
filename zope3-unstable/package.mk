# $NetBSD: package.mk,v 1.2 2006/01/03 03:50:42 ykomatsu Exp $
#

DEPENDS+=		zope3-unstable>=3.2.0b3:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
