# $NetBSD: Makefile,v 1.8 2014/01/21 20:40:51 lexort Exp $

UPSTREAM_VERSION=	0.22
VERSION=	${UPSTREAM_VERSION}.${SVN_VERSION}
SVN_VERSION=	12834

DISTNAME=	TracSensitiveTickets-${VERSION}
PKGNAME=	trac-plugins-SensitiveTickets-${VERSION}
# Empty PKGREVISION because svn-package by default sets one.
PKGREVISION=	
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
WRKSRC=		${WRKDIR}/sensitivetickets

NO_CHECKSUM=	yes

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
