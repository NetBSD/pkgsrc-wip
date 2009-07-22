# $NetBSD: Makefile,v 1.1.1.1 2009/07/22 13:33:21 lexort Exp $

VERSION=	0.0.${SVN_VERSION}
SVN_VERSION=	5285

DISTNAME=	TracSensitiveTickets-${VERSION}
PKGNAME=	trac-plugins-SensitiveTickets-${VERSION}
# Empty PKGREVISION because svn-package by default sets one.
PKGREVISION=
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/SensitiveTicketsPlugin
COMMENT=	Ticket dependency plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	sensitivetickets
SVN_ROOT.sensitivetickets=	http://trac-hacks.org/svn/sensitiveticketsplugin/0.11
SVN_TAG.sensitivetickets=	${SVN_VERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/sensitivetickets

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
