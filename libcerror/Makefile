# $NetBSD: Makefile,v 1.3 2013/05/28 12:14:20 othyro Exp $
#

DISTNAME=	libcerror-alpha-20130411
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	http://libcerror.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcerror/
COMMENT=	Library for cross-platform C error functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcerror-20130411
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcerror.pc.in

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
