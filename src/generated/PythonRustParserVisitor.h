
// Generated from grammar/PythonRustParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PythonRustParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PythonRustParser.
 */
class  PythonRustParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PythonRustParser.
   */
    virtual std::any visitProgram(PythonRustParser::ProgramContext *context) = 0;

    virtual std::any visitStmt(PythonRustParser::StmtContext *context) = 0;

    virtual std::any visitSimple_stmt(PythonRustParser::Simple_stmtContext *context) = 0;

    virtual std::any visitSmall_stmt(PythonRustParser::Small_stmtContext *context) = 0;

    virtual std::any visitExpr_stmt(PythonRustParser::Expr_stmtContext *context) = 0;

    virtual std::any visitAnnassign(PythonRustParser::AnnassignContext *context) = 0;

    virtual std::any visitReturn_stmt(PythonRustParser::Return_stmtContext *context) = 0;

    virtual std::any visitImport_stmt(PythonRustParser::Import_stmtContext *context) = 0;

    virtual std::any visitImport_list(PythonRustParser::Import_listContext *context) = 0;

    virtual std::any visitDotted_name(PythonRustParser::Dotted_nameContext *context) = 0;

    virtual std::any visitRaise_stmt(PythonRustParser::Raise_stmtContext *context) = 0;

    virtual std::any visitPass_stmt(PythonRustParser::Pass_stmtContext *context) = 0;

    virtual std::any visitFlow_stmt(PythonRustParser::Flow_stmtContext *context) = 0;

    virtual std::any visitCompound_stmt(PythonRustParser::Compound_stmtContext *context) = 0;

    virtual std::any visitIf_stmt(PythonRustParser::If_stmtContext *context) = 0;

    virtual std::any visitWhile_stmt(PythonRustParser::While_stmtContext *context) = 0;

    virtual std::any visitFor_stmt(PythonRustParser::For_stmtContext *context) = 0;

    virtual std::any visitTry_stmt(PythonRustParser::Try_stmtContext *context) = 0;

    virtual std::any visitExcept_clause(PythonRustParser::Except_clauseContext *context) = 0;

    virtual std::any visitFuncdef(PythonRustParser::FuncdefContext *context) = 0;

    virtual std::any visitClassdef(PythonRustParser::ClassdefContext *context) = 0;

    virtual std::any visitSuite(PythonRustParser::SuiteContext *context) = 0;

    virtual std::any visitParameters(PythonRustParser::ParametersContext *context) = 0;

    virtual std::any visitParam(PythonRustParser::ParamContext *context) = 0;

    virtual std::any visitArglist(PythonRustParser::ArglistContext *context) = 0;

    virtual std::any visitKwArg(PythonRustParser::KwArgContext *context) = 0;

    virtual std::any visitPosArg(PythonRustParser::PosArgContext *context) = 0;

    virtual std::any visitTarget_list(PythonRustParser::Target_listContext *context) = 0;

    virtual std::any visitTarget(PythonRustParser::TargetContext *context) = 0;

    virtual std::any visitTestlist(PythonRustParser::TestlistContext *context) = 0;

    virtual std::any visitType(PythonRustParser::TypeContext *context) = 0;

    virtual std::any visitAndExpr(PythonRustParser::AndExprContext *context) = 0;

    virtual std::any visitMulDivExpr(PythonRustParser::MulDivExprContext *context) = 0;

    virtual std::any visitMemberExpr(PythonRustParser::MemberExprContext *context) = 0;

    virtual std::any visitCompExpr(PythonRustParser::CompExprContext *context) = 0;

    virtual std::any visitCallExpr(PythonRustParser::CallExprContext *context) = 0;

    virtual std::any visitNotExpr(PythonRustParser::NotExprContext *context) = 0;

    virtual std::any visitAtomExpr(PythonRustParser::AtomExprContext *context) = 0;

    virtual std::any visitUnaryExpr(PythonRustParser::UnaryExprContext *context) = 0;

    virtual std::any visitAddSubExpr(PythonRustParser::AddSubExprContext *context) = 0;

    virtual std::any visitOrExpr(PythonRustParser::OrExprContext *context) = 0;

    virtual std::any visitIndexExpr(PythonRustParser::IndexExprContext *context) = 0;

    virtual std::any visitSubscript(PythonRustParser::SubscriptContext *context) = 0;

    virtual std::any visitSlice(PythonRustParser::SliceContext *context) = 0;

    virtual std::any visitIntAtom(PythonRustParser::IntAtomContext *context) = 0;

    virtual std::any visitFloatAtom(PythonRustParser::FloatAtomContext *context) = 0;

    virtual std::any visitStringAtom(PythonRustParser::StringAtomContext *context) = 0;

    virtual std::any visitTrueAtom(PythonRustParser::TrueAtomContext *context) = 0;

    virtual std::any visitFalseAtom(PythonRustParser::FalseAtomContext *context) = 0;

    virtual std::any visitNoneAtom(PythonRustParser::NoneAtomContext *context) = 0;

    virtual std::any visitIdAtom(PythonRustParser::IdAtomContext *context) = 0;

    virtual std::any visitListAtom(PythonRustParser::ListAtomContext *context) = 0;

    virtual std::any visitSetDictAtom(PythonRustParser::SetDictAtomContext *context) = 0;

    virtual std::any visitGroupOrTupleAtom(PythonRustParser::GroupOrTupleAtomContext *context) = 0;

    virtual std::any visitList_maker(PythonRustParser::List_makerContext *context) = 0;

    virtual std::any visitSet_or_dict(PythonRustParser::Set_or_dictContext *context) = 0;

    virtual std::any visitDict_kv(PythonRustParser::Dict_kvContext *context) = 0;

    virtual std::any visitComp_clause(PythonRustParser::Comp_clauseContext *context) = 0;


};

