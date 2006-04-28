# $NetBSD: package.mk,v 1.4 2006/04/28 11:30:15 ykomatsu Exp $
#

DEPENDS+=		zope3>=3.2.1:../../wip/zope3-unstable

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
