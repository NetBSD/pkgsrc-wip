# $NetBSD: Makefile,v 1.4 2010/06/10 14:45:05 lexort Exp $

VERSION=	0.1.${SVN_VERSION}
SVN_VERSION=	5285

DISTNAME=	TracSensitiveTickets-${VERSION}
PKGNAME=	trac-plugins-SensitiveTickets-${VERSION}
# Empty PKGREVISION because svn-package by default sets one.
PKGREVISION=	2
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

# setup.py says "GPL".
LICENSE=	gnu-gpl-v2

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
