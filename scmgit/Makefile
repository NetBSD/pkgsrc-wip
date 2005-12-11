# $NetBSD: Makefile,v 1.1.1.1 2005/12/11 12:26:28 poppnk Exp $
#

DISTNAME=		git-0.99.9l
PKGNAME=			scm${DISTNAME}
CATEGORIES=		wip devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/git/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://git.or.cz/
COMMENT=		Tree History Storage Tool

MAKE_ENV=	"DESTDIR=${PREFIX}/"
MAKE_ENV+=	"HOME=."
USE_TOOLS+=	gmake

# TODO: add python as dependency? or just show a message?
# I prefer no python dependency.

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
