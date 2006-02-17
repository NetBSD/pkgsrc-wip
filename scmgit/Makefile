# $NetBSD: Makefile,v 1.4 2006/02/17 18:25:28 poppnk Exp $
#

DISTNAME=		git-1.2.1
PKGNAME=			scm${DISTNAME}
CATEGORIES=		wip devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/git/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://git.or.cz/
COMMENT=		Tree History Storage Tool

MAKE_ENV=	"DESTDIR="
MAKE_ENV+=	"HOME=${PREFIX}/"
USE_TOOLS+=	gmake

# TODO: add python as dependency? or just show a message?
# I prefer no python dependency.

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
