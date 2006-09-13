# $NetBSD: package.mk,v 1.7 2006/09/13 09:23:14 ykomatsu Exp $
#

DEPENDS+=		zope3>=3.3.0c1:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
