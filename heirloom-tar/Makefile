# $NetBSD: Makefile,v 1.3 2006/12/21 08:33:29 cheusov Exp $

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../wip/heirloom-common/Makefile.prog2.common"

PKGNAME=	heirloom-tar-${HEIRLOOM_VER}
CATEGORIES=	sysutils

DOC_FILES=	NOTES

MAKE_FLAGS+=	SUBDIRS="libcommon build tar"

.include "../../mk/bsd.pkg.mk"
