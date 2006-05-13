# $NetBSD: package.mk,v 1.5 2006/05/13 12:09:32 ykomatsu Exp $
#

DEPENDS+=		zope3>=3.3.0b1:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
