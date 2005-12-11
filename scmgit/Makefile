# $NetBSD: Makefile,v 1.2 2005/12/11 13:21:03 poppnk Exp $
#

DISTNAME=		git-0.99.9l
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
