# $NetBSD: Makefile,v 1.4 2012/11/07 03:09:51 othyro Exp $
#

DISTNAME=	alsa-plugins-1.0.18
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture plugins

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake pkg-config

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
