# $NetBSD: Makefile,v 1.2 2013/01/10 15:43:52 othyro Exp $
#

DISTNAME=	libcerror-alpha-20121222
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	http://libcerror.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcerror/
COMMENT=	Library for cross-platform C error functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcerror-20121222
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcerror.pc.in

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
