# $NetBSD: Makefile,v 1.7 2013/02/21 19:18:03 lexort Exp $

UPSTREAM_VERSION=	0.21
VERSION=	${UPSTREAM_VERSION}.${SVN_VERSION}
SVN_VERSION=	11910

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

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

EGG_NAME=	sensitivetickets-${UPSTREAM_VERSION}

SVN_REPOSITORIES=	sensitivetickets
SVN_ROOT.sensitivetickets=	http://trac-hacks.org/svn/sensitiveticketsplugin/trunk
SVN_TAG.sensitivetickets=	${SVN_VERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/sensitivetickets/trunk

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
