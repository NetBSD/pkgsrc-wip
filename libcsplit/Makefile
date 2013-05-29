# $NetBSD: Makefile,v 1.1 2013/05/29 11:11:21 othyro Exp $

DISTNAME=	libcsplit-alpha-20121224
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	textproc
MASTER_SITES=	http://libcsplit.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcsplit/
COMMENT=	Library for cross-platform C split string functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcsplit-20121224
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcsplit.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
