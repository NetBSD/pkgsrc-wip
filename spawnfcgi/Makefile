# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 15:51:24 mjoellnir Exp $
#

DISTNAME=	spawn-fcgi-1.6.2
CATEGORIES=	net www
MASTER_SITES=	http://www.lighttpd.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vs@nifelheim.info
HOMEPAGE=	http://redmine.lighttpd.net/projects/spawn-fcgi
COMMENT=	Spawns FCGI-Processes and runs with priviledge separation

PKG_DESTDIR_SUPPORT=    user-destdir

CONFLICTS=       lighttpd<1.4.23

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+= --libdir=${PREFIX}/lib/${PKGBASE}

DOCDIR=                 ${PREFIX}/share/doc/${PKGBASE}
EGDIR=                  ${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=      ${PKGBASE}

RCD_SCRIPTS=            spawnfcgi

INSTALLATION_DIRS=      ${DOCDIR} ${EGDIR}

post-install:
	cd ${WRKSRC}; for f in AUTHORS COPYING ChangeLog NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
