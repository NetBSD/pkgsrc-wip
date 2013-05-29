# $NetBSD: Makefile,v 1.1 2013/05/29 10:29:25 othyro Exp $

DISTNAME=	libcnotify-alpha-20121224
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	sysutils
MASTER_SITES=	http://libcnotify.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/libcnotify/
COMMENT=	Library to support cross-platform C notification functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libcnotify-20121224
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcnotify.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
