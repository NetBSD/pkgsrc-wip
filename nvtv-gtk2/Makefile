# $NetBSD: Makefile,v 1.2 2003/09/29 04:28:10 cubidou Exp $

PKGNAME=	${DISTNAME:S/-/-gtk2-/}
.include "../../wip/nvtv/Makefile.common"

CONFLICTS=	nvtv-[0-9]*

DESCR_SRC=	${PKGDIR}/../../wip/nvtv/DESCR
DISTINFO_FILE=	${PKGDIR}/../../wip/nvtv/distinfo
FILESDIR=	${PKGDIR}/../../wip/nvtv/files
PLIST_SRC=	${PKGDIR}/../../wip/nvtv/PLIST
PATCHDIR=	${PKGDIR}/../../wip/nvtv/patches

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
