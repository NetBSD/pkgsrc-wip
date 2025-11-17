# $NetBSD$

DISTNAME=	fstrcmp-0.7.D001
CATEGORIES=	devel
MASTER_SITES=	http://fstrcmp.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fstrcmp.sourceforge.net/
COMMENT=	Library for fuzzy comparisons of strings
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config ps2pdf
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libdir/pkgconfig/fstrcmp.pc.in

.include "../../mk/bsd.pkg.mk"
