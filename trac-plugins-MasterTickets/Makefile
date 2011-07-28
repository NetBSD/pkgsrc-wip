# $NetBSD: Makefile,v 1.6 2011/07/28 12:26:39 lexort Exp $

UPSTREAM_VERSION=	2.1.3
VERSION=	${UPSTREAM_VERSION}.4179
DISTNAME=	TracMasterTickets-${VERSION}
PKGNAME=	trac-plugins-MasterTickets-${VERSION}
# Empty PKGREVISION because svn-package by default sets one.
PKGREVISION=	3
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/MasterTicketsPlugin
COMMENT=	Ticket dependency plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

EGG_NAME=	TracMasterTickets-${UPSTREAM_VERSION}

SVN_REPOSITORIES=	mastertickets
SVN_ROOT.mastertickets=	http://trac-hacks.org/svn/masterticketsplugin/0.11
SVN_TAG.mastertickets=	4179

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/mastertickets

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

# MasterTickets uses graphviz directly (rather than via the GraphViz plugin).
# \todo Make this optional.
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
