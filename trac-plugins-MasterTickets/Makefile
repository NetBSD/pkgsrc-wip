# $NetBSD: Makefile,v 1.1.1.1 2009/02/24 20:21:51 lexort Exp $

DISTNAME=	TracMasterTickets-2.1.3.5305
PKGNAME=	trac-plugins-MasterTickets-2.1.3.5305
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/MasterTicketsPlugin
COMMENT=	Ticket dependency plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	mastertickets
SVN_ROOT.mastertickets=	http://trac-hacks.org/svn/masterticketsplugin/0.11
SVN_TAG.mastertickets=	5305

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/mastertickets

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
