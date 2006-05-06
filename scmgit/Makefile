# $NetBSD: Makefile,v 1.6 2006/05/06 02:14:29 jeremy-c-reed Exp $
#

DISTNAME=		git-1.3.1
PKGNAME=		scm${DISTNAME}
CATEGORIES=		wip devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/git/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://git.or.cz/
COMMENT=		Tree History Storage Tool

CONFLICTS+=		git-* # misc/git

MAKE_ENV=	"DESTDIR="
MAKE_ENV+=	HOME=${PREFIX:Q}
USE_TOOLS+=	gmake
USE_TOOLS+=	perl:run

MAKE_ENV+=	PERL_PATH=${PERL5:Q}
MAKE_ENV+=	PYTHON_PATH=${PYTHONBIN:Q}
#MAKE_ENV+=	SHELL_PATH=${SH:Q}

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
