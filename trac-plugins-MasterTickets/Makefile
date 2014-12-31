# $NetBSD: Makefile,v 1.13 2014/12/31 13:58:47 thomasklausner Exp $

UPSTREAM_VERSION=	3.0.4
DISTNAME=	TracMasterTickets-${UPSTREAM_VERSION}
VERSION=	${UPSTREAM_VERSION}.${SVN_TAG.mastertickets}
PKGNAME=	trac-plugins-MasterTickets-${VERSION}
# PKGREVISION must exist for svn, or else it will get a date
PKGREVISION=
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/MasterTicketsPlugin
COMMENT=	Ticket dependency plugin for Trac
LICENSE=	modified-bsd

DEPENDS+=	{ja-,}trac>=1.0:../../www/trac

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.0.4/r12946

SVN_REPOSITORIES=		mastertickets
SVN_ROOT.mastertickets=		http://trac-hacks.org/svn/masterticketsplugin/trunk
# Upsteam has tagged 3.0.4 at r12946
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
