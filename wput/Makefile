# $NetBSD: Makefile,v 1.12 2012/11/03 16:50:38 othyro Exp $
#

DISTNAME=	wput-0.6.2
PKGREVISION=	2
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
INSTALL_ENV+=		DESTDIR=${DESTDIR} PKGMANDIR=${PKGMANDIR}

MAKE_JOBS_SAFE=		no

.include "options.mk"


.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
