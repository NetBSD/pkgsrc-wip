# $NetBSD: Makefile,v 1.2 2011/12/03 20:39:58 mrampke Exp $

# fetching by tag from GitHub needs some special treatment
DISTNAME=       ${GHUSER}-${GHNAME}-${GHTAG}-${GHREV}-g${GHCOMMIT}
PKGNAME=        ${GHNAME}-${GHTAG:S/^v//}-${GHREV}
WRKSRC=         ${WRKDIR}/${GHUSER}-${GHNAME}-${GHCOMMIT}
MASTER_SITES=   https://github.com/${GHUSER}/${GHNAME}/tarball/${GHCOMMIT}/
FETCH_USING=    curl

# the GitHub user you want to fetch from
GHUSER=         gnosek
# the repository name
GHNAME=         fcgiwrap
# the last tag on this branch - if this is not in the form of "v${PKGVERSION}" adjust the PKGNAME!
GHTAG=          1.0.3
# commits since this tag
GHREV=		4
# the tagged commit hash, 7 places
GHCOMMIT=       58ec209


CATEGORIES=	www
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap
COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
