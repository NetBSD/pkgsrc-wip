# $NetBSD: Makefile,v 1.1 2012/12/08 22:41:37 othyro Exp $
#

DISTNAME=	libcerror-alpha-20120507
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	http://libclibs.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libclibs/
COMMENT=	Several libraries for cross-platform C functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcerror-20120507
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcerror.pc.in

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
