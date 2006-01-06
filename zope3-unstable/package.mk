# $NetBSD: package.mk,v 1.3 2006/01/06 00:47:21 ykomatsu Exp $
#

DEPENDS+=		zope3>=3.2.0:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
