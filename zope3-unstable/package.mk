# $NetBSD: package.mk,v 1.6 2006/08/20 11:47:49 ykomatsu Exp $
#

DEPENDS+=		zope3>=3.3.0b2:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
