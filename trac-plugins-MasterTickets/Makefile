# $NetBSD: Makefile,v 1.11 2014/01/21 21:39:42 lexort Exp $

UPSTREAM_VERSION=	3.0.4
DISTNAME=	TracMasterTickets-${UPSTREAM_VESRION}
VERSION=	${UPSTREAM_VERSION}.${SVN_TAG.mastertickets}
PKGNAME=	trac-plugins-MasterTickets-${VERSION}
# PKGREVISION must exist for svn, or else it will get a date
PKGREVISION=
CATEGORIES=	www
MASTER_SITES=	# not defined

LICENSE=	modified-bsd

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/MasterTicketsPlugin
COMMENT=	Ticket dependency plugin for Trac

EGG_NAME=	${DISTNAME}

DEPENDS+=	{ja-,}trac>=1.0:../../www/trac

EGG_NAME=	TracMasterTickets-${UPSTREAM_VERSION}

SVN_REPOSITORIES=		mastertickets
SVN_ROOT.mastertickets=		http://trac-hacks.org/svn/masterticketsplugin/trunk
# This appears to be the release, but there is no tag.
SVN_TAG.mastertickets=		12946

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/mastertickets

#post-extract:
#	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

# MasterTickets uses graphviz directly (rather than via the GraphViz plugin).
# \todo Make this optional.
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
