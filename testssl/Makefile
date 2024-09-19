# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	testssl-3.0rc5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=drwetter/}
GITHUB_PROJECT=	testssl.sh
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://testssl.sh/
COMMENT=	Checks servers for TLS/SSL flaws
LICENSE=	gnu-gpl-v2

# Do we need more depends for runtime tools?
DEPENDS+=	bash-[0-9]*:../../shells/bash

# Tests are run with "prove" (which is provided with lang/perl5),
# a number of tests fail right now + Test::More needs to be packaged.
TEST_DEPENDS+=	perl5-[0-9]*:../../lang/perl5
TEST_DEPENDS+=	p5-Data-Dumper-[0-9]*:../../devel/p5-Data-Dumper
TEST_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
#TEST_DEPENDS+=	p5-Test-More-[0-9]*:../../devel/p5-Test-More

NO_BUILD=		yes
INSTALLATION_DIRS=	bin share/doc/${PKGBASE} etc/${PKGBASE}

REPLACE_INTERPRETER+=	envbash
REPLACE.envbash.old=	'/usr/bin/env\ bash'
REPLACE.envbash.new=	${PREFIX}/bin/bash
REPLACE_FILES.envbash=	testssl.sh

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/testssl.sh ${DESTDIR}${PREFIX}/bin/testssl
	${INSTALL_DATA} ${WRKSRC}/Readme.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README.md

# Maybe patch in the path to TESTSSL_INSTALL_DIR?
post-install:
.for f in ca_hashes.txt cipher-mapping.txt client-simulation.txt client-simulation.wiresharked.txt common-primes.txt curves.txt tls_data.txt
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DESTDIR}${PREFIX}/etc/${PKGBASE}
.endfor

do-test:
	( cd ${WRKSRC} && ${PREFIX}/bin/prove -v )

.include "../../mk/bsd.pkg.mk"
