# $NetBSD: Makefile,v 1.6 2009/06/30 13:03:24 jihbed Exp $
#

DISTNAME=	task-1.7.1
CATEGORIES=	time
MASTER_SITES=	http://www.taskwarrior.org/download/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://taskwarrior.org/projects/show/taskwarrior/
COMMENT=	Task is an open source, command-line, TODO list manager
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	share/doc/task ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../mk/bsd.pkg.mk"
