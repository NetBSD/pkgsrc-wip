# $NetBSD: Makefile,v 1.5 2012/10/07 16:23:16 asau Exp $
#

DISTNAME=	spawn-fcgi-1.6.2
CATEGORIES=	net www
MASTER_SITES=	http://www.lighttpd.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vs@nifelheim.info
HOMEPAGE=	http://redmine.lighttpd.net/projects/spawn-fcgi
COMMENT=	Spawns FCGI-Processes and runs with priviledge separation
LICENSE=        modified-bsd

CONFLICTS=       lighttpd<1.4.23

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}

DOCDIR=                 ${PREFIX}/share/doc/${PKGBASE}
PKG_SYSCONFSUBDIR=      ${PKGBASE}

RCD_SCRIPTS=            spawnfcgi

INSTALLATION_DIRS=      ${DOCDIR}

post-install:
	cd ${WRKSRC}; for f in AUTHORS COPYING NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
