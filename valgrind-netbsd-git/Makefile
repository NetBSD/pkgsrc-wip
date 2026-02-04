# $NetBSD$

DISTNAME=	valgrind-netbsd-0.0.20260203
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=paulfloyd/}
# head of branch of 'fosdem26' as of date above
GITHUB_TAG=	542995e04e0f69815d4d2e22918bbc5a0c4dabd4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paulfloyd/valgrind-netbsd
COMMENT=	NetBSD port of Valgrind
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/valgrind-netbsd-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	automake autoconf autoreconf gmake perl

TEST_TARGET=	check

CHECK_RELRO_SKIP+=	libexec/valgrind/cachegrind-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/callgrind-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/dhat-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/drd-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/exp-bbv-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/helgrind-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/lackey-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/massif-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/memcheck-amd64-netbsd
CHECK_RELRO_SKIP+=	libexec/valgrind/none-amd64-netbsd

PKGSRC_MKPIE=	no

REPLACE_PERL+=		callgrind/callgrind_annotate.in
REPLACE_PERL+=		callgrind/callgrind_control.in
REPLACE_PYTHON+=	cachegrind/cg_annotate.in
REPLACE_PYTHON+=	cachegrind/cg_diff.in
REPLACE_PYTHON+=	cachegrind/cg_merge.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
