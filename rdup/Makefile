# $NetBSD: Makefile,v 1.4 2010/05/24 18:16:43 emil_s Exp $
#

DISTNAME=	rdup-1.1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.miek.nl/projects/rdup/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://www.miek.nl/projects/rdup/
COMMENT=	Backup utility listing changed files only
LICENSE=	gnu-gpl-v3

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	sh/rdup-simple.in


PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_TOOLS=	pkg-config gmake bash:run

MAKE_FILE=	GNUmakefile


.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
