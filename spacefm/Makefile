# $NetBSD: Makefile,v 0.3 2018/09/11 14:44:10 andyb Exp $


GITHUB_PROJECT=	spacefm
DISTNAME=	1.0.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=IgnorantGuru/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	andyb@m42.one
HOMEPAGE=	https://github.com/IgnorantGuru/spacefm/
COMMENT=	SpaceFM Filemanager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/spacefm-1.0.6
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	perl gmake pkg-config automake autoconf

DEPENDS+=	libX11-[0-9]*:../../x11/libX11
DEPENDS+=	hal-[0-9]*:../../sysutils/hal
DEPENDS+=	desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils
DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
