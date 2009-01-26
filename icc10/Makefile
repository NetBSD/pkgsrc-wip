# $NetBSD: Makefile,v 1.2 2009/01/26 20:01:00 alnsn Exp $

ICC_VERSION=	10.1.021
ICC_SUBPREFIX=	icc10
CATEGORIES=	lang
DISTNAME=	l_cc_p_${ICC_VERSION}
PKGNAME=	${ICC_SUBPREFIX}-${ICC_VERSION}
MASTER_SITES=# empty

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	http://www.intel.com/cd/software/products/asmo-na/eng/compilers/
COMMENT=	Intel C++ Compiler for Linux

RESTRICTED=	Intel forbids any redistribution
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
LICENSE=	intel-icc10-license

ICC_PREFIX=		${PREFIX}/${ICC_SUBPREFIX}

ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64

DEPENDS+=		gcc43>=4.3.2:../../wip/gcc43
BUILD_DEPENDS+=		rpm2pkg>=2.1:../../pkgtools/rpm2pkg

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base compat
EMUL_REQD=		suse>=10.0

NO_BUILD=		yes

.include "../../mk/bsd.prefs.mk"

PLIST_SUBST+=		ICC_SUBPREFIX=${ICC_SUBPREFIX}

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	/bin/sh
REPLACE_FILES.bash=	${ICC_SUBPREFIX}/bin/icc       \
			${ICC_SUBPREFIX}/bin/icpc      \
			${ICC_SUBPREFIX}/bin/profrun   \
			${ICC_SUBPREFIX}/bin/iccvars.sh

STARTFILES=			crt0.o crti.o crtbegin.o
ENDFILES=			crtn.o crtend.o
INTERP=				/usr/libexec/ld.elf_so

SUBST_CLASSES+=			installdir vars

SUBST_MESSAGE.installdir=	Substituting <INSTALLDIR>
SUBST_STAGE.installdir=		pre-configure
SUBST_SED.installdir=		-e 's,<INSTALLDIR>,${ICC_PREFIX},g'
SUBST_FILES.installdir=		${ICC_SUBPREFIX}/bin/icc        \
				${ICC_SUBPREFIX}/bin/icpc       \
				${ICC_SUBPREFIX}/bin/iccvars.sh \
                       		${ICC_SUBPREFIX}/bin/iccvars.csh

SUBST_STAGE.vars=		pre-configure
SUBST_VARS.vars=		BUILDLINK_PREFIX.gcc43 INTERP \
				STARTFILES ENDFILES
SUBST_FILES.vars=		${ICC_SUBPREFIX}/bin/icc  \
				${ICC_SUBPREFIX}/bin/icpc

.if ${MACHINE_ARCH}=="i386"
ICC_EXTRACT_RPM=data/intel-icc${ICC_VERSION:S/.//g}-${ICC_VERSION}-1.i386.rpm
.else
ICC_EXTRACT_RPM=data/intel-icce${ICC_VERSION:S/.//g}-${ICC_VERSION}-1.em64t.rpm
.endif

post-extract:
	@( cd ${WRKSRC:Q} && rpm2pkg -s 4 ${ICC_EXTRACT_RPM} &&           \
	${TOOLS_PLATFORM.mv} ${ICC_VERSION} ${ICC_SUBPREFIX} &&           \
	${TOOLS_PLATFORM.rm} -rf ${ICC_SUBPREFIX}/bin/uninstall.sh        \
		${ICC_SUBPREFIX}/include ${ICC_SUBPREFIX}/eclipse_support \
		${ICC_SUBPREFIX}/lib/*.so* )

do-install:
	@( cd ${WRKSRC:Q} && \
	${TOOLS_PLATFORM.cp} -R ${ICC_SUBPREFIX} ${LOCALBASE:Q} )

.include "../../wip/gcc43/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
