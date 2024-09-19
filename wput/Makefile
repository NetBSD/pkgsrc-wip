# $NetBSD: Makefile,v 1.13 2013/04/13 16:03:57 othyro Exp $
#

DISTNAME=	wput-0.6.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wput/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wput.sourceforge.net/
COMMENT=	Wput is a command-line ftp-client that looks like wget
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt msgmerge xgettext
CONFIGURE_ARGS+=	--mandir=${PKGMANDIR}

MAKE_JOBS_SAFE=		no

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
