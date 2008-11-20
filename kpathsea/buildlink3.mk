# $NetBSD: buildlink3.mk,v 1.2 2008/11/20 01:22:31 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KPATHSEA_BUILDLINK3_MK:=	${KPATHSEA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kpathsea
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkpathsea}
BUILDLINK_PACKAGES+=	kpathsea
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kpathsea

.if ${KPATHSEA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kpathsea+=	kpathsea>=3.5.7
BUILDLINK_PKGSRCDIR.kpathsea?=	../../wip/kpathsea
.endif	# KPATHSEA_BUILDLINK3_MK

.if !empty(TEXMFDIRS)
_TEXMFDIRS=	# empty
.for _texmfdir_ in ${TEXMFDIRS}
_TEXMFDIRS+=	${PREFIX}/${_texmfdir_}
.endfor
FILES_SUBST+=		TEXMFDIRS=${_TEXMFDIRS:Q}
FILES_SUBST+=		MKTEXLSR="${BUILDLINK_PREFIX.kpathsea}/bin/mktexlsr"
INSTALL_TEMPLATES+=	../../wip/kpathsea/files/texmf-install.tmpl
DEINSTALL_TEMPLATES+=	../../wip/kpathsea/files/texmf-deinstall.tmpl

.for _texmfdir_ in ${TEXMFDIRS}
PRINT_PLIST_AWK+=       /^${_texmfdir_:S|/|\\/|g}\/ls-R$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${_texmfdir_:S|/|\\/|g}$$/ { next; }
.endfor
.endif

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
