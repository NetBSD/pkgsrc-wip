# $NetBSD$

DISTNAME=	efibootmgr-18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhboot/efibootmgr/releases/download/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rhboot/efibootmgr/
COMMENT=	Tool to modify the EFI boot manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
MAKE_FLAGS+=	EFIDIR=XXX_do_not_know
CPPFLAGS+=	-I${PREFIX}/include/efivar

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/popt/buildlink3.mk"
.include "../../wip/efivar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
