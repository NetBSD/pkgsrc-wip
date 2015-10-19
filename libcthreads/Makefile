# $NetBSD: Makefile,v 1.1 2014/02/03 09:41:37 othyro Exp $
#

DISTNAME=	libcthreads-experimental-20150101
GITHUB_PROJECT=	libcthreads
GITHUB_RELEASE=	${PKGVERSION_NOREV}
PKGNAME=	${DISTNAME:S/-experimental//1}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libcthreads/
COMMENT=	Library for cross-platform C threads functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libcthreads.pc.in

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
